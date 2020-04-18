#!/bin/bash

# Kill all edgex-* stuff
function cleanup {
	pkill edgex
}

# disable secret-store integration
export EDGEX_SECURITY_SECRET_STORE=false

###
# Support logging
###
exec -a edgex-support-logging support-logging --confdir=/etc/edgex/support-logging &

###
# Core Command
###
exec -a edgex-core-command core-command --confdir=/etc/edgex/core-command &

###
# Core Data
###
exec -a edgex-core-data core-data --confdir=/etc/edgex/core-data &

###
# Core Metadata
###
exec -a edgex-core-metadata core-metadata --confdir=/etc/edgex/core-metadata &

###
# Export Client
###
exec -a edgex-export-client export-client --confdir=/etc/edgex/export-client &

###
# Export Distro
###
exec -a edgex-export-distro export-distro --confdir=/etc/edgex/export-distro &

###
# Support Notifications
###
exec -a edgex-support-notifications support-notifications --confdir=/etc/edgex/support-notifications &

###
# System Management Agent
###
exec -a edgex-sys-mgmt-agent sys-mgmt-agent --confdir=/etc/edgex/sys-mgmt-agent &

# Support Scheduler
###
exec -a edgex-support-scheduler support-scheduler --confdir=/etc/edgex/support-scheduler &

trap cleanup EXIT

while : ; do sleep 1 ; done