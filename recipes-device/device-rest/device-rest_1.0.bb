require device-rest.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-rest-go.git;protocol=https;branch=master \
           file://device-rest.toml \
           file://device-rest-launch.sh \
           "
SRCREV = "210f50c9adcd32d3bf7f0011a8b75df57d2f34bd"