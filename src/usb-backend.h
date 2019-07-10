/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
    Copyright (C) 2018 Red Hat, Inc.

    Red Hat Authors:
    Yuri Benditovich<ybendito@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SPICE_USB_BACKEND_H__
#define __SPICE_USB_BACKEND_H__

#include <usbredirfilter.h>
#include "usb-device-manager.h"

G_BEGIN_DECLS

typedef struct _SpiceUsbBackend SpiceUsbBackend;
typedef struct _SpiceUsbBackendDevice SpiceUsbBackendDevice;
typedef struct _SpiceUsbBackendChannel SpiceUsbBackendChannel;

typedef struct UsbDeviceInformation
{
    uint16_t bus;
    uint16_t address;
    uint16_t vid;
    uint16_t pid;
    uint8_t class;
    uint8_t subclass;
    uint8_t protocol;
} UsbDeviceInformation;

typedef void(*usb_hot_plug_callback)(void *user_data, SpiceUsbBackendDevice *dev, gboolean added);

enum {
    USB_REDIR_ERROR_IO = -1,
    USB_REDIR_ERROR_READ_PARSE = -2,
    USB_REDIR_ERROR_DEV_REJECTED = -3,
    USB_REDIR_ERROR_DEV_LOST = -4,
};

/* Spice USB backend API */
/* sets error on failure */
SpiceUsbBackend *spice_usb_backend_new(GError **error);
void spice_usb_backend_delete(SpiceUsbBackend *context);

/*
returns newly-allocated null-terminated list of
SpiceUsbBackendDevice pointers.
The caller must call spice_usb_backend_free_device_list
after it finishes list processing
*/
SpiceUsbBackendDevice **spice_usb_backend_get_device_list(SpiceUsbBackend *backend);
void spice_usb_backend_free_device_list(SpiceUsbBackendDevice **devlist);
gboolean spice_usb_backend_handle_events(SpiceUsbBackend *be);
gboolean spice_usb_backend_register_hotplug(SpiceUsbBackend *be,
                                            void *user_data,
                                            usb_hot_plug_callback proc);
void spice_usb_backend_deregister_hotplug(SpiceUsbBackend *be);

/* Spice USB backend device API */
SpiceUsbBackendDevice *spice_usb_backend_device_ref(SpiceUsbBackendDevice *dev);
void spice_usb_backend_device_unref(SpiceUsbBackendDevice *dev);
gconstpointer spice_usb_backend_device_get_libdev(SpiceUsbBackendDevice *dev);
const UsbDeviceInformation* spice_usb_backend_device_get_info(SpiceUsbBackendDevice *dev);
gboolean spice_usb_backend_device_isoch(SpiceUsbBackendDevice *dev);
/* returns 0 if the device passes the filter */
int spice_usb_backend_device_check_filter(SpiceUsbBackendDevice *dev,
                                          const struct usbredirfilter_rule *rules, int count);

/* Spice USB backend channel API */
SpiceUsbBackendChannel *spice_usb_backend_channel_new(SpiceUsbBackend *context,
                                                      void            *user_data);
void spice_usb_backend_channel_delete(SpiceUsbBackendChannel *ch);
/* returns 0 for success or error code */
int spice_usb_backend_read_guest_data(SpiceUsbBackendChannel *ch, uint8_t *data, int count);
GError *spice_usb_backend_get_error_details(int error_code, gchar *device_desc);
gboolean spice_usb_backend_channel_attach(SpiceUsbBackendChannel *ch,
                                          SpiceUsbBackendDevice *dev,
                                          GError **error);
void spice_usb_backend_channel_detach(SpiceUsbBackendChannel *ch);
void spice_usb_backend_channel_flush_writes(SpiceUsbBackendChannel *ch);
void spice_usb_backend_channel_get_guest_filter(SpiceUsbBackendChannel *ch,
                                                const struct usbredirfilter_rule  **rules,
                                                int *count);
void spice_usb_backend_return_write_data(SpiceUsbBackendChannel *ch, void *data);

G_END_DECLS

#endif
