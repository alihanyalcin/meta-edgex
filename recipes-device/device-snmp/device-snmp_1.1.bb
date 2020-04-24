require device-snmp.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/device-snmp-go.git;protocol=https;branch=fuji \
           file://device-snmp.toml \
           "
SRCREV = "ad615bec9e539dc3946133789203e72853746a46"