require device-virtual.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-virtual-go.git;protocol=https;branch=fuji \
           file://device-virtual.toml \
           file://device-virtual-launch.sh \
           "
SRCREV = "f44840606597ebf86bf382287249641137948033"