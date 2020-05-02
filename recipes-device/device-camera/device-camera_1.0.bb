require device-camera.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-camera-go.git;protocol=https;branch=master \
           file://device-camera.toml \
           file://device-camera-launch.sh \
           "
SRCREV = "8f23dd60e3fe2f3e94ad557fda6de9b613243bce"