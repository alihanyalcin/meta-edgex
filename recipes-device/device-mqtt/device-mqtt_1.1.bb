require device-mqtt.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-mqtt-go.git;protocol=https;branch=fuji \
           file://device-mqtt.toml \
           file://device-mqtt-launch.sh \
           "
SRCREV = "f519bc1280f873a40e1f5dd58196830efd3e4795"