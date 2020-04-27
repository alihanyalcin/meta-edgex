require device-modbus.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-modbus-go.git;protocol=https;branch=fuji \
           file://device-modbus.toml \
           file://device-modbus-launch.sh \
           "
SRCREV = "37c94ae483882d8c56a71f3776c70874920714ed"