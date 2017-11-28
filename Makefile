MIQ=make-it-quick/
SUBDIRS=src tools
include $(MIQ)rules.mk
$(MIQ)rules.mk:
	git clone http://github.com/c3d/make-it-quick
