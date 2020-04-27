#!/bin/bash

function cleanup {
	pkill edgex-device-random
}

exec -a edgex-device-random device-random --confdir=/etc/edgex/device-random &

trap cleanup EXIT

while : ; do sleep 1 ; done