#!/bin/bash

# Kill all edgex-ui-server* stuff
function cleanup {
	pkill edgex-ui-server
}

cd /etc/edgex/edgex-ui-server
exec -a edgex-ui-server edgex-ui-server &

trap cleanup EXIT

while : ; do sleep 1 ; done