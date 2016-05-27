Name:		capi-network-wifi
Summary:	Network Wi-Fi library in TIZEN C API
Version:	1.0.45
Release:	1
Group:		System/Network
License:	Apache-2.0
Source0:	%{name}-%{version}.tar.gz
BuildRequires:	cmake
BuildRequires:	pkgconfig(dlog)
BuildRequires:	pkgconfig(vconf)
BuildRequires:	pkgconfig(network)
BuildRequires:	pkgconfig(glib-2.0)
BuildRequires:	pkgconfig(capi-base-common)
BuildRequires:	pkgconfig(capi-system-info)
BuildRequires:	model-build-features
Requires(post):		/sbin/ldconfig
Requires(postun):	/sbin/ldconfig

%if "%{?tizen_profile_name}" == "wearable"
BuildRequires:  pkgconfig(capi-appfw-application)
%endif

%description
Network Wi-Fi library in Tizen C API

%package devel
Summary:	Network Wi-Fi library in Tizen C API (Development)
Group:		System/Network
Requires:	%{name} = %{version}-%{release}

%description devel
Network Wi-Fi library in Tizen C API (Development)

%prep
%setup -q


%build
export CFLAGS+=' -Wno-unused-local-typedefs'
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
cmake -DCMAKE_INSTALL_PREFIX=/usr -DFULLVER=%{version} -DMAJORVER=${MAJORVER} \
%if 0%{?model_build_feature_network_dsds} == 1
	-DTIZEN_DUALSIM_ENABLE=1 \
%endif
%if "%{?tizen_profile_name}" == "wearable"
	-DTIZEN_WEARABLE=1 \
%elseif "%{?tizen_profile_name}" == "mobile"
	-DTIZEN_MOBILE=1 \
%endif
	.

make %{?_smp_mflags}


%install
%make_install

#License
mkdir -p %{buildroot}%{_datadir}/license
cp LICENSE %{buildroot}%{_datadir}/license/capi-network-wifi

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%manifest capi-network-wifi.manifest
%attr(644,-,-) %{_libdir}/libcapi-network-wifi.so.*
%{_datadir}/license/capi-network-wifi
%{_bindir}/wifi_test

%files devel
%{_includedir}/network/*.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/libcapi-network-wifi.so
