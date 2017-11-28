TOP=../
MIQ=$(TOP)make-it-quick/

PACKAGE_NAME=	spice-gtk
PACKAGE_VERSION=0.3.2
PACKAGE_BUGS=	spice-devel@lists.freedesktop.org
PACKAGE_DESCRIPTION=SPICE GTK 3.0 client
VARIANTS=	viewer stats snap

PRODUCTS=	$(PRODUCTS_$(VARIANT))
PRODUCTS_viewer=spicy.exe
PRODUCTS_stats= spicy-stats.exe
PRODUCTS_snap=	spicy-screenshot.exe

SOURCES=	spice-cmdline.c						\
		$(SOURCES_$(VARIANT))
SOURCES_viewer= spicy-connect.c						\
		spicy.c

SOURCES_stats=	spicy-stats.c
SOURCES_snap=	spicy-screenshot.c

PKGCONFIGS=	gstreamer-1.0						\
		gstreamer-app-1.0					\
		gstreamer-video-1.0					\
		gstreamer-audio-1.0					\
		glib-2.0						\
		gtk+-3.0						\
		celt051?						\
		libpulse?						\
		libpulse-mainloop-glib?

SPICE_COMMON?=	$(TOP)subprojects/spice-common/
ifndef SPICE_PROTOCOL
PKGCONFIGS+=	spice-protocol
endif

CONFIG=		<termios.h>						\
		gstaudio						\
		gstvideo						\
		libacl

DEFINES=	GETTEXT_PACKAGE=\"spice-gtk\"				\
		SPICE_COMPILATION					\
		PACKAGE_BUGREPORT='"$(PACKAGE_BUGS)"'			\
		PACKAGE_VERSION='"$(PACKAGE_VERSION)"'

INCLUDES=	.							\
		../src							\
		$(SPICE_PROTOCOL)					\
		$(SPICE_COMMON)

LIBRARIES=	../src/spice-client-glib-2.0.dll			\
		../src/spice-client-gtk-3.0.dll				\
		$(SPICE_COMMON)spice-common-client.dll

include $(MIQ)rules.mk

$(MIQ)rules.mk:
	cd $(TOP) && make $(MIQ)rules.mk
