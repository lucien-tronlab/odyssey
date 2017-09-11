#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start odysseyd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/odysseyd
  cp /usr/local/bin/odyssey-sv-run.sh /etc/service/odysseyd/run
  chmod +x /etc/service/odysseyd/run
  runsv /etc/service/odysseyd
else
  /usr/local/bin/startpaasodysseyd.sh
fi
