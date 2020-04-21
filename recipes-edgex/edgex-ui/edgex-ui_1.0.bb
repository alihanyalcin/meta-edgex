require edgex-ui.inc

DESCRIPTION = "EdgeX Web UI"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/edgex-ui-go.git;protocol=https;branch=master \
           file://edgex-ui-server.toml \
           "
SRCREV = "5bd33396c4899597419799a7a42603b405e21a38"