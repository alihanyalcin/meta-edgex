require device-random.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-random.git;protocol=https;branch=fuji \
           file://device-random.toml \
           file://device-random-launch.sh \
           "
SRCREV = "632a155c8fb68d204d9b95ad3c38ca6d19298346"