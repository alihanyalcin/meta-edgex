require edgex.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/alihanyalcin/edgex-go.git;protocol=https;branch=fuji \
           file://edgex-fuji-launch.sh"
SRCREV = "6662b85e1fd9872482e1ba2f1197cd669978afb1"