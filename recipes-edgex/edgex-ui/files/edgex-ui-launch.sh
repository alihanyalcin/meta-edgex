#!/bin/bash

# Kill all edgex-ui-go* stuff
function cleanup {
	pkill edgex-ui-server
}

cd $CMD
exec -a edgex-ui-server edgex-ui-server --conf=/etc/edgex/edgex-ui-server/configuration.toml &
cd $DIR

trap cleanup EXIT

while : ; do sleep 1 ; done