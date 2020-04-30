require device-random.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-random.git;protocol=https;branch=fuji \
           file://device-random.toml \
           file://device-random-launch.sh \
           "
SRCREV = "632a155c8fb68d204d9b95ad3c38ca6d19298346"