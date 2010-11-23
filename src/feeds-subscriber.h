/*
 * Copyright (C) 2009, Roberto Guido <rguido@src.gnome.org>
 *                     Michele Tameni <michele@amdplanet.it>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#ifndef __FEEDS_SUBSCRIBER_H__
#define __FEEDS_SUBSCRIBER_H__

#include "libgrss.h"

#define FEEDS_SUBSCRIBER_TYPE		(grss_feeds_subscriber_get_type())
#define FEEDS_SUBSCRIBER(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), FEEDS_SUBSCRIBER_TYPE, GrssFeedsSubscriber))
#define FEEDS_SUBSCRIBER_CLASS(c)	(G_TYPE_CHECK_CLASS_CAST ((c), FEEDS_SUBSCRIBER_TYPE, GrssFeedsSubscriberClass))
#define IS_FEEDS_SUBSCRIBER(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), FEEDS_SUBSCRIBER_TYPE))
#define IS_FEEDS_SUBSCRIBER_CLASS(c)	(G_TYPE_CHECK_CLASS_TYPE ((c),  FEEDS_SUBSCRIBER_TYPE))
#define FEEDS_SUBSCRIBER_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), FEEDS_SUBSCRIBER_TYPE, GrssFeedsSubscriberClass))

typedef struct _GrssFeedsSubscriber		GrssFeedsSubscriber;
typedef struct _GrssFeedsSubscriberPrivate	GrssFeedsSubscriberPrivate;

struct _GrssFeedsSubscriber {
	GObject parent;
	GrssFeedsSubscriberPrivate *priv;
};

typedef struct {
	GObjectClass parent;

	void (*notification_received) (GrssFeedsSubscriber *sub, GrssFeedChannel *feed, GrssFeedItem *item);
} GrssFeedsSubscriberClass;

GType			grss_feeds_subscriber_get_type		() G_GNUC_CONST;

GrssFeedsSubscriber*	grss_feeds_subscriber_new		();

gboolean		grss_feeds_subscriber_listen		(GrssFeedsSubscriber *sub, GList *feeds);
GList*			grss_feeds_subscriber_get_listened	(GrssFeedsSubscriber *sub);
void			grss_feeds_subscriber_set_port		(GrssFeedsSubscriber *sub, int port);
void			grss_feeds_subscriber_set_hub		(GrssFeedsSubscriber *sub, gchar *hub);
void			grss_feeds_subscriber_switch		(GrssFeedsSubscriber *sub, gboolean run);

#endif /* __FEEDS_SUBSCRIBER_H__ */
