require device-rest.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-rest-go.git;protocol=https;branch=master \
           file://device-rest.toml \
           file://device-rest-launch.sh \
           "
SRCREV = "210f50c9adcd32d3bf7f0011a8b75df57d2f34bd"