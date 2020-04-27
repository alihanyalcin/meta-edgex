#!/bin/bash

function cleanup {
	pkill edgex-device-mqtt
}

exec -a edgex-device-mqtt device-mqtt --confdir=/etc/edgex/device-mqtt &

trap cleanup EXIT

while : ; do sleep 1 ; done