#!/bin/bash

# Kill all edgex-* stuff
function cleanup {
    pkill edgex
}

# Support Logging
exec -a edgex-support-logging support-logging &

# Core Command
exec -a edgex-core-command core-command &

# Core Data
exec -a edgex-core-data ./core-data &

# Core Metadata
exec -a edgex-core-metadata ./core-metadata &

# Export Client
exec -a edgex-export-client ./export-client &

# Export Distro
exec -a edgex-export-distro ./export-distro &

# Support Notifications
exec -a edgex-support-notifications ./support-notifications &

# System Management Agent
exec -a edgex-sys-mgmt-agent ./sys-mgmt-agent &

# Support Scheduler
exec -a edgex-support-scheduler ./support-scheduler &

trap cleanup EXIT

while : ; do sleep 1 ; done