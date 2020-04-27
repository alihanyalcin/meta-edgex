#!/bin/bash

function cleanup {
	pkill edgex-device-virtual
}

exec -a edgex-device-virtual device-virtual --confdir=/etc/edgex/device-virtual &

trap cleanup EXIT

while : ; do sleep 1 ; done