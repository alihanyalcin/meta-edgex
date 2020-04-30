require device-modbus.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-modbus-go.git;protocol=https;branch=fuji \
           file://device-modbus.toml \
           file://device-modbus-launch.sh \
           "
SRCREV = "37c94ae483882d8c56a71f3776c70874920714ed"