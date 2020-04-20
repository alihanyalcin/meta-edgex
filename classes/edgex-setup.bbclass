# ------------------------------ SETUP CONFIGURATION ---------------------------------
EDGEX = "edgex"

# EdgeX executable files destination directory
EDGEX_BIN = "${bindir}"

# EdgeX configuration files destination directory
EDGEX_ETC = "${sysconfdir}/${EDGEX}"

# EdgeX log files directory
EDGEX_LOG = "${localstatedir}/log/${EDGEX}"

EDGEX_CONFIGURATION_FILE = "configuration.toml"

MICROSERVICES = "config-seed \
                 core-command \
                 core-data \
                 core-metadata \
                 export-client \
                 export-distro \
                 support-logging \
                 support-notifications \
                 support-scheduler \
                 sys-mgmt-agent \
                 security-secrets-setup \
                 security-proxy-setup \
                 security-secretstore-setup \
                "        
# --------------------------- END OF SETUP CONFIGURATION -----------------------------