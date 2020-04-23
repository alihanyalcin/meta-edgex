require device-virtual.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-virtual-go.git;protocol=https;branch=fuji \
           file://device-virtual.toml \
           "
SRCREV = "f44840606597ebf86bf382287249641137948033"