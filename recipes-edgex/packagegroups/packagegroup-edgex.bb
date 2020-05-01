DESCRIPTION = "EdgeX Package Groups"

inherit packagegroup

PACKAGES = "\
    packagegroup-edgex-all \
    packagegroup-edgex-services \
    packagegroup-edgex-devices \
    "

RDEPENDS_packagegroup-edgex-all = " \
    packagegroup-edgex-services \
    packagegroup-edgex-devices \
    "

SUMMARY_packagegroup-edgex-services = "EdgeX Services and EdgeX UI"
RDEPENDS_packagegroup-edgex-services =  " \
    edgex \
    edgex-ui \
    "   

SUMMARY_packagegroup-edgex-devices = "EdgeX Devices"
RDEPENDS_packagegroup-edgex-devices = " \
    device-modbus \
    device-mqtt \
    device-random \
    device-rest \
    device-snmp \
    device-virtual \
    "