#!/bin/bash

function cleanup {
	pkill edgex-device-rest
}

exec -a edgex-device-rest device-rest --confdir=/etc/edgex/device-rest &

trap cleanup EXIT

while : ; do sleep 1 ; done