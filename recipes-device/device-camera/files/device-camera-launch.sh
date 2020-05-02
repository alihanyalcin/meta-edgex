#!/bin/bash

function cleanup {
	pkill edgex-device-camera
}

exec -a edgex-device-camera device-camera --confdir=/etc/edgex/device-camera &

trap cleanup EXIT

while : ; do sleep 1 ; done