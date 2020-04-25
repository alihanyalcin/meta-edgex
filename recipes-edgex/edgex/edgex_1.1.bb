require edgex.inc

DESCRIPTION = "EdgeX Foundry Services - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/edgex-go.git;protocol=https;branch=fuji \
           file://edgex-fuji-launch.sh \
           file://config-seed.toml \
           file://core-command.toml \
           file://core-data.toml \
           file://core-metadata.toml \
           file://export-client.toml \
           file://export-distro.toml \
           file://support-logging.toml \
           file://support-notifications.toml \
           file://support-scheduler.toml \
           file://sys-mgmt-agent.toml \
           file://security-secrets-setup.toml \
           file://security-proxy-setup.toml \
           file://security-secretstore-setup.toml \
           "
SRCREV = "5c8c324351b6d4ffa4082e3c9028b357a4c7dc67"