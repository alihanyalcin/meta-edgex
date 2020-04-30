require device-mqtt.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-mqtt-go.git;protocol=https;branch=fuji \
           file://device-mqtt.toml \
           file://device-mqtt-launch.sh \
           "
SRCREV = "f519bc1280f873a40e1f5dd58196830efd3e4795"