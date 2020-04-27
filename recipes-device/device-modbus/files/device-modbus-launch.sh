#!/bin/bash

function cleanup {
	pkill edgex-device-modbus
}

exec -a edgex-device-modbus device-modbus --confdir=/etc/edgex/device-modbus &

trap cleanup EXIT

while : ; do sleep 1 ; done