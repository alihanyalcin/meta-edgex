require device-snmp.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-snmp-go.git;protocol=https;branch=fuji \
           file://device-snmp.toml \
           file://device-snmp-launch.sh \
           "
SRCREV = "ad615bec9e539dc3946133789203e72853746a46"