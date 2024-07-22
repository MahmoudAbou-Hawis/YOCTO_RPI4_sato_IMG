require recipes-sato/images/core-image-sato.bb

DESCRIPTION = "Custom Sato Image without games"


IMAGE_NAME = "MySatoimage-2.7.9"

IMAGE_FEATURES:remove = " x11-sato"

IMAGE_FEATURE:append = " splash"

IMAGE_INSTALL += " packagegroup-core-x11-sato-base"
IMAGE_INSTALL += " bluez5"

IMAGE_INSTALL:append = " calc"
IMAGE_INSTALL:append = " calculator"
