#!/bin/bash

function cleanup {
	pkill edgex-device-snmp
}

exec -a edgex-device-snmp device-snmp --confdir=/etc/edgex/device-snmp &

trap cleanup EXIT

while : ; do sleep 1 ; done