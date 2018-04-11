TOP=../../

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

PKGCONFIGS=	spice-protocol						\
		gstreamer-1.0						\
		gstreamer-app-1.0					\
		gstreamer-video-1.0					\
		gstreamer-audio-1.0					\
		glib-2.0						\
		gtk+-3.0						\
		celt051?						\
		libpulse?						\
		libpulse-mainloop-glib?

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
		../spice-common

LIBRARIES=	../src/spice-client-glib-2.0.8.dll			\
		../src/spice-client-gtk-3.0.dll				\
		../spice-common/spice-common-client.dll

include make-it-quick/rules.mk
