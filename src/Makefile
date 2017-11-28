TOP=../../../
BUILD=$(TOP)build/

VARIANTS=	config glib gtk

PRODUCTS=	$(PRODUCTS_$(VARIANT))
PRODUCTS_glib=	spice-client-glib-2.0.8.dll
PRODUCTS_gtk=	spice-client-gtk-3.0.dll

PACKAGE_VERSION=0.14.6

BUILTIN_MJPEG=	HAVE_BUILTIN_MJPEG
ACL_HELPER_PATH=$(PREFIX_BIN)

PKGCONFIGS=	pixman-1						\
		openssl							\
		gstreamer-1.0						\
		gstreamer-app-1.0					\
		gstreamer-video-1.0					\
		gstreamer-audio-1.0					\
		gstreamer-plugins-base-1.0				\
		gio-2.0							\
		gio-unix-2.0						\
		glib-2.0						\
		atk							\
		zlib							\
		libjpeg							\
		gtk+-3.0						\
		polkit-gobject-1?

CONFIG=		$(CONFIG_$(VARIANT))
CONFIG_glib=	$(CONFIG_config)
CONFIG_gtk=	$(CONFIG_config)
CONFIG_config=	<sys/socket.h>						\
		<sys/types.h>						\
		<netinet/in.h>						\
		<arpa/inet.h>						\
		<termios.h>						\
		<epoxy/egl.h>						\
		<ucontext.h>						\
		<polkit/polkit.h>					\
		<acl/libacl.h>						\
		<pulse/glib-mainloop.h>					\
		<X11/XKBlib.h>						\
		<pygobject.h>						\
		strtok_r						\
		clearenv						\
		libacl							\
		GSTVIDEO						\
		GSTAUDIO						\
		PULSE							\
		EGL							\
		GDK_EVENT_GET_SCANCODE					\
		POLKIT_AUTHORITY_GET_SYNC				\
		POLKIT_AUTHORIZATION_RESULT_GET_DISMISSED

INCLUDES=	.							\
		.. 							\
		$(TOP)protocol						\
		$(TOP)libs/recorder					\
		$(TOP)libs/common					\
		$(TOP)libs

DEFINES=	SPICE_COMPILATION					\
		PACKAGE_STRING=\"GSpice\"				\
		G_LOG_DOMAIN=\"GSpice\"					\
		VERSION=\"$(PACKAGE_VERSION)\"				\
		GETTEXT_PACKAGE=\"spice-gtk\"				\
		LOCALE_DIR=\"$(PREFIX_SHARE)share/locale\"		\
		SPICE_GTK_LOCALEDIR=\"$(PREFIX_SHARE)share/locale\"	\
		PNP_IDS='${pnpdatadir}/pnp.ids'				\
		USB_IDS=\"\"						\
		WITH_UCONTEXT=HAVE_UCONTEXT_H				\
		ACL_HELPER_PATH=\"$(ACL_HELPER_PATH)\"			\
		GLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_46		\
		GLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_2_46		\
		$(BUILTIN_MJPEG)					\
		$(DEFINES_$(OS_NAME))
DEFINES_macosx=	_XOPEN_SOURCE

SOURCES=	$(SOURCES_$(VARIANT))					\
		$(SOURCES_$(OS_NAME))

SOURCES_glib=	$(SOURCES_coroutine)					\
		bio-gio.c						\
		channel-base.c						\
		channel-cursor.c					\
		channel-display-gst.c					\
		channel-display-mjpeg.c					\
		channel-display.c					\
		channel-inputs.c					\
		channel-main.c						\
		channel-playback.c					\
		channel-port.c						\
		channel-record.c					\
		channel-smartcard.c					\
		channel-usbredir.c					\
		channel-webdav.c					\
		client_sw_canvas.c					\
		continuation.c						\
		decode-glz.c						\
		decode-jpeg.c						\
		decode-zlib.c						\
		gio-coroutine.c						\
		giopipe.c                               		\
		smartcard-manager.c					\
		spice-audio.c						\
		spice-channel.c						\
		spice-client.c						\
		$(HAVE_PYOBJECT_H:%=	 spice-client-gtk-module.c)	\
		spice-file-transfer-task.c				\
		spice-glib-enums.c					\
		spice-glib-main.c					\
		$(HAVE_GSTAUDIO:%=		spice-gstaudio.c)	\
		spice-marshal.c						\
		spice-option.c						\
		$(HAVE_PULSE_GLIB_MAINLOOP_H:%=	spice-pulse.c)		\
		spice-session.c						\
		spice-uri.c						\
		spice-util.c						\
		$(HAVE_ACL_LIBACL_H:%=		usb-acl-helper.c	\
		$(HAVE_POLKIT_POLKIT_H:%=				\
			          spice-client-glib-usb-acl-helper.c))	\
		usb-device-manager.c					\
		usbutil.c						\
		vmcstream.c

SOURCES_gtk=	desktop-integration.c					\
		spice-grabsequence.c					\
		spice-gtk-session.c					\
		spice-marshal.c						\
		spice-util.c						\
		spice-widget-cairo.c					\
		$(HAVE_EGL:%=			spice-widget-egl.c)	\
		spice-widget-enums.c					\
		spice-widget.c						\
		usb-device-widget.c					\
		vncdisplaykeymap.c

SOURCES_windows=win-usb-dev.c						\
		usbdk_api.c

CFLAGS_vncdisplaykeymap=	$(CFLAGS_ObjC_$(OS_NAME))
CFLAGS_ObjC_macosx=-ObjC

LIBRARIES=	$(TOP)libs/common/spice-common-client.dll		\
		$(LIBRARIES_$(VARIANT))
LIBRARIES_gtk=	$(PRODUCTS_glib)

# Headers to install
PREFIX_HDR=	$(PREFIX)include/$(PREFIX_HDR_$(VARIANT))
HDR_INSTALL=	$(HEADERS_$(VARIANT))

PREFIX_HDR_gtk=spice-client-gtk-3.0/
HEADERS_gtk=				\
	spice-client-gtk.h		\
	spice-gtk-session.h		\
	spice-widget.h			\
	spice-grabsequence.h		\
	usb-device-widget.h		\

PREFIX_HDR_glib=spice-client-glib-2.0/
HEADERS_glib=				\
	spice-audio.h			\
	spice-client.h			\
	spice-uri.h			\
	spice-types.h			\
	spice-session.h			\
	spice-channel.h			\
	spice-util.h			\
	spice-option.h			\
	spice-version.h			\
	channel-cursor.h		\
	channel-display.h		\
	channel-inputs.h		\
	channel-main.h			\
	channel-playback.h		\
	channel-port.h			\
	channel-record.h		\
	channel-smartcard.h		\
	channel-usbredir.h		\
	channel-webdav.h		\
	usb-device-manager.h		\
	smartcard-manager.h		\
	spice-file-transfer-task.h	\

include $(BUILD)rules.mk

# Coroutine configuration: first Windows, then ucontext, then ghtread
COROUTINE=	$(firstword						\
			$(COROUTINE_$(OS_NAME))				\
			$(HAVE_UCONTEXT_H:%=ucontext)			\
			gthread)
COROUTINE_windows=winfibers

SOURCES_coroutine=							\
		coroutine_$(COROUTINE).c

SPICE_GTK_MAJOR_VERSION=$(shell echo $(PACKAGE_VERSION) | cut -d. -f1)
SPICE_GTK_MINOR_VERSION=$(shell echo $(PACKAGE_VERSION) | cut -d. -f2)
SPICE_GTK_MICRO_VERSION=$(shell echo $(PACKAGE_VERSION) | cut -d. -f3 | cut -d- -f1)

GENERATED_FILES =spice-glib-enums.c					\
		spice-glib-enums.h					\
		spice-marshal.c						\
		spice-marshal.h						\
		spice-widget-enums.c					\
		spice-widget-enums.h					\
		spice-version.h						\
		$(KEYMAPS)

TO_CLEAN=$(GENERATED_FILES)

prebuild: $(GENERATED_FILES)

# Generated files

spice-version.h: spice-version.h.in $(MAKEFILE_DEPS)
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-version.h=							\
	sed < $< > $@ 							\
	-e 's|@SPICE_GTK_MAJOR_VERSION@|$(SPICE_GTK_MAJOR_VERSION)|g'	\
	-e 's|@SPICE_GTK_MINOR_VERSION@|$(SPICE_GTK_MINOR_VERSION)|g' 	\
	-e 's|@SPICE_GTK_MICRO_VERSION@|$(SPICE_GTK_MICRO_VERSION)|g'

spice-marshal.c: spice-marshal.h
spice-marshal.c spice-marshal.h: spice-marshal.txt
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-marshal.c=							\
	echo "\#include \"config.h\"" > $@ && 				\
	echo "\#include \"spice-marshal.h\"" > $@ && 			\
	glib-genmarshal --body $< >> $@ || (rm -f $@ && exit 1)
GEN_spice-marshal.h=							\
	glib-genmarshal --header $< > $@ || (rm -f $@ && exit 1)
spice-glib-enum.c: spice-glib-emum.h
spice-glib-enums.c: spice-channel.h channel-inputs.h spice-session.h
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-glib-enums.c=							\
	glib-mkenums							\
	--fhead "\#include \"config.h\"\n\n" 				\
	--fhead "\#include <glib-object.h>\n" 				\
	--fhead "\#include \"spice-glib-enums.h\"\n\n" 			\
	--fprod "\n\#include \"spice-session.h\"\n" 			\
	--fprod "\n\#include \"spice-channel.h\"\n" 			\
	--fprod "\n\#include \"channel-inputs.h\"\n" 			\
	--vhead "static const G@Type@Value _@enum_name@_values[] = {"	\
	--vprod "  { @VALUENAME@, \"@VALUENAME@\", \"@valuenick@\" },"	\
	--vtail "  { 0, NULL, NULL }\n};\n\n"				\
	--vtail "GType\n@enum_name@_get_type (void)\n{\n"		\
	--vtail "  static GType type = 0;\n"				\
	--vtail "  static volatile gsize type_volatile = 0;\n\n"	\
	--vtail "  if (g_once_init_enter(&type_volatile)) {\n"		\
	--vtail "    type = g_@type@_register_static (\"@EnumName@\", _@enum_name@_values);\n" \
	--vtail "    g_once_init_leave(&type_volatile, type);\n"	\
	--vtail "  }\n\n"						\
	--vtail "  return type;\n}\n\n"					\
	$^ > $@

spice-glib-enums.h: spice-channel.h channel-inputs.h spice-session.h
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-glib-enums.h=							\
	glib-mkenums							\
	--fhead "\#ifndef SPICE_GLIB_ENUMS_H\n"				\
	--fhead "\#define SPICE_GLIB_ENUMS_H\n\n"			\
	--fhead "G_BEGIN_DECLS\n\n"					\
	--ftail "G_END_DECLS\n\n" 					\
	--ftail "\#endif /* SPICE_CHANNEL_ENUMS_H */\n" 			\
	--eprod "\#define SPICE_TYPE_@ENUMSHORT@ @enum_name@_get_type()\n" \
	--eprod "GType @enum_name@_get_type (void);\n"			\
	$^ >  $@

spice-widget-enums.c: spice-widget.h
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-widget-enums.c=						\
	glib-mkenums --fhead "\#include \"config.h\"\n\n"		\
	--fhead "\#include <glib-object.h>\n"				\
	--fhead "\#include \"spice-widget-enums.h\"\n\n"		\
	--fprod "\n\#include \"spice-widget.h\"\n"			\
	--vhead "static const G@Type@Value _@enum_name@_values[] = {"	\
	--vprod "  { @VALUENAME@, \"@VALUENAME@\", \"@valuenick@\" },"	\
	--vtail "  { 0, NULL, NULL }\n};\n\n"				\
	--vtail "GType\n@enum_name@_get_type (void)\n{\n"		\
	--vtail "  static GType type = 0;\n"				\
	--vtail "  static volatile gsize type_volatile = 0;\n\n"	\
	--vtail "  if (g_once_init_enter(&type_volatile)) {\n"		\
	--vtail "    type = g_@type@_register_static (\"@EnumName@\", _@enum_name@_values);\n" \
	--vtail "    g_once_init_leave(&type_volatile, type);\n"	\
	--vtail "  }\n\n"						\
	--vtail "  return type;\n}\n\n"					\
	$< > $@

spice-widget-enums.h: spice-widget.h
	$(PRINT_GENERATE) $(GEN_$@)
GEN_spice-widget-enums.h=						\
	glib-mkenums							\
	--fhead "\#ifndef SPICE_WIDGET_ENUMS_H\n"			\
	--fhead "\#define SPICE_WIDGET_ENUMS_H\n\n"			\
	--fhead "G_BEGIN_DECLS\n\n"					\
	--ftail "G_END_DECLS\n\n"					\
	--ftail "\#endif /* SPICE_WIDGET_ENUMS_H */\n"			\
	--eprod "\#define SPICE_TYPE_@ENUMSHORT@ @enum_name@_get_type()\n" \
	--eprod "GType @enum_name@_get_type (void);\n"			\
	$< >  $@

# Keymaps
KEYMAP_GEN= keycodemapdb/tools/keymap-gen
KEYMAP_CSV= keycodemapdb/data/keymaps.csv
KEYMAPS=								\
	vncdisplaykeymap_xorgevdev2xtkbd.c				\
	vncdisplaykeymap_xorgkbd2xtkbd.c				\
	vncdisplaykeymap_xorgxquartz2xtkbd.c				\
	vncdisplaykeymap_xorgxwin2xtkbd.c				\
	vncdisplaykeymap_osx2xtkbd.c					\
	vncdisplaykeymap_win322xtkbd.c					\
	vncdisplaykeymap_x112xtkbd.c

vncdisplaykeymap.c: $(KEYMAPS)
$(KEYMAPS): $(KEYMAP_GEN) $(KEYMAP_CSV)
	$(PRINT_GENERATE) $(GENKEYMAP)
GENKEYMAP=	$(GENKM1) $(GENKM1_$@) $(GENKM2) $(GENKM2_$@) $(GENKM3)
GENKM1=		$(PYTHON) $(KEYMAP_GEN) --lang glib2 --varname
GENKM2=		code-map $(KEYMAP_CSV)
GENKM3=		xtkbd > $@ || rm $@
GENKM1_vncdisplaykeymap_xorgevdev2xtkbd.c=	keymap_xorgevdev2xtkbd
GENKM2_vncdisplaykeymap_xorgevdev2xtkbd.c=	xorgevdev
GENKM1_vncdisplaykeymap_xorgkbd2xtkbd.c=	keymap_xorgkbd2xtkbd
GENKM2_vncdisplaykeymap_xorgkbd2xtkbd.c=	xorgkbd
GENKM1_vncdisplaykeymap_xorgxquartz2xtkbd.c=	keymap_xorgxquartz2xtkbd
GENKM2_vncdisplaykeymap_xorgxquartz2xtkbd.c=	xorgxquartz
GENKM1_vncdisplaykeymap_xorgxwin2xtkbd.c=	keymap_xorgxwin2xtkbd
GENKM2_vncdisplaykeymap_xorgxwin2xtkbd.c=	xorgxwin
GENKM1_vncdisplaykeymap_osx2xtkbd.c=		keymap_osx2xtkbd
GENKM2_vncdisplaykeymap_osx2xtkbd.c=		osx
GENKM1_vncdisplaykeymap_win322xtkbd.c=		keymap_win322xtkbd
GENKM2_vncdisplaykeymap_win322xtkbd.c=		win32
GENKM1_vncdisplaykeymap_x112xtkbd.c=		keymap_x112xtkbd
GENKM2_vncdisplaykeymap_x112xtkbd.c=		x11
