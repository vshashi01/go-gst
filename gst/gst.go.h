#ifndef __GST_GO_H__
#define __GST_GO_H__

#include <stdlib.h>
#include <gst/gst.h>

/*
	Type Castings
*/

inline GstAllocator *         toGstAllocator         (void *p) { return (GST_ALLOCATOR_CAST(p)); }
inline GstBin *               toGstBin               (void *p) { return (GST_BIN(p)); }
inline GstBufferList *        toGstBufferList        (void *p) { return (GST_BUFFER_LIST(p)); }
inline GstBufferPool *        toGstBufferPool        (void *p) { return (GST_BUFFER_POOL(p)); }
inline GstBuffer *            toGstBuffer            (void *p) { return (GST_BUFFER(p)); }
inline GstBus *               toGstBus               (void *p) { return (GST_BUS(p)); }
inline GstCapsFeatures *      toGstCapsFeatures      (void *p) { return (GST_CAPS_FEATURES(p)); }
inline GstCaps *              toGstCaps              (void *p) { return (GST_CAPS(p)); }
inline GstClock *             toGstClock             (void *p) { return (GST_CLOCK(p)); }
inline GstContext *           toGstContext           (void *p) { return (GST_CONTEXT_CAST(p)); }
inline GstDevice *            toGstDevice            (void *p) { return (GST_DEVICE_CAST(p)); }
inline GstElementFactory *    toGstElementFactory    (void *p) { return (GST_ELEMENT_FACTORY(p)); }
inline GstElement *           toGstElement           (void *p) { return (GST_ELEMENT(p)); }
inline GstEvent *             toGstEvent             (void *p) { return (GST_EVENT(p)); }
inline GstGhostPad *          toGstGhostPad          (void *p) { return (GST_GHOST_PAD(p)); }
inline GstMemory *            toGstMemory            (void *p) { return (GST_MEMORY_CAST(p)); }
inline GstMessage *           toGstMessage           (void *p) { return (GST_MESSAGE(p)); }
inline GstMeta *              toGstMeta              (void *p) { return (GST_META_CAST(p)); }
inline GstMiniObject *        toGstMiniObject        (void *p) { return (GST_MINI_OBJECT(p)); }
inline GstObject *            toGstObject            (void *p) { return (GST_OBJECT(p)); }
inline GstPad *               toGstPad               (void *p) { return (GST_PAD(p)); }
inline GstPadTemplate *       toGstPadTemplate       (void *p) { return (GST_PAD_TEMPLATE(p)); }
inline GstPipeline *          toGstPipeline          (void *p) { return (GST_PIPELINE(p)); }
inline GstPluginFeature *     toGstPluginFeature     (void *p) { return (GST_PLUGIN_FEATURE(p)); }
inline GstPlugin *            toGstPlugin            (void *p) { return (GST_PLUGIN(p)); }
inline GstProxyPad *          toGstProxyPad          (void *p) { return (GST_PROXY_PAD(p)); }
inline GstQuery *             toGstQuery             (void *p) { return (GST_QUERY(p)); }
inline GstRegistry *          toGstRegistry          (void *p) { return (GST_REGISTRY(p)); }
inline GstSample *            toGstSample            (void *p) { return (GST_SAMPLE(p)); }
inline GstStreamCollection *  toGstStreamCollection  (void *p) { return (GST_STREAM_COLLECTION_CAST(p)); }
inline GstStream *            toGstStream            (void *p) { return (GST_STREAM_CAST(p)); }
inline GstStructure *         toGstStructure         (void *p) { return (GST_STRUCTURE(p)); }
inline GstTagList   *         toGstTagList           (void *p) { return (GST_TAG_LIST(p)); }
inline GstTask *              toGstTask              (void *p) { return (GST_TASK_CAST(p)); }
inline GstTaskPool *          toGstTaskPool          (void *p) { return (GST_TASK_POOL_CAST(p)); }
inline GstURIHandler *        toGstURIHandler        (void *p) { return (GST_URI_HANDLER(p)); }
inline GstUri *               toGstURI               (void *p) { return (GST_URI(p)); }

/* Buffer Utilities */

inline GstBuffer * getBufferValue (GValue * val)
{
	return gst_value_get_buffer(val);
}

inline gboolean bufferIsWritable (GstBuffer * buf)
{
	return (gst_buffer_is_writable(buf));
}

inline GstBuffer * makeBufferWritable (GstBuffer * buf)
{
	return (gst_buffer_make_writable(buf));
}

inline GType bufferListType ()
{
	return GST_TYPE_BUFFER_LIST;
}

/* BufferList Utilities */

inline gboolean bufferListIsWritable (GstBufferList * bufList)
{
	return gst_buffer_list_is_writable(bufList);
}

inline GstBufferList * makeBufferListWritable (GstBufferList * bufList)
{
	return gst_buffer_list_make_writable(bufList);
}

inline void addToBufferList (GstBufferList * bufList, GstBuffer * buf)
{
	gst_buffer_list_add(bufList, buf);
}

/* BufferPool utilities */

inline gboolean bufferPoolIsFlushing (GstBufferPool * pool)
{
	return GST_BUFFER_POOL_IS_FLUSHING(pool);
}

/* Caps utilties */

inline gboolean capsIsWritable (GstCaps * caps)
{
	return gst_caps_is_writable(caps);
}

inline GstCaps * makeCapsWritable (GstCaps * caps)
{
	return gst_caps_make_writable(caps);
}

inline GType getCapsType ()
{
	return GST_TYPE_CAPS;
}

/* Context utilities */

inline gboolean contextIsWritable (GstContext * ctx)
{
	return gst_context_is_writable(ctx);
}

inline GstContext * makeContextWritable (GstContext * ctx)
{
	return gst_context_make_writable(ctx);
}

/* Event Utilities */

inline gboolean eventIsWritable (GstEvent * event)
{
	return gst_event_is_writable(event);
}

inline GstEvent * makeEventWritable (GstEvent * event)
{
	return gst_event_make_writable(event);
}

/* TOC Utilities */

inline gboolean         entryTypeIsAlternative (GstTocEntryType * type) { return GST_TOC_ENTRY_TYPE_IS_ALTERNATIVE(type); }
inline gboolean         entryTypeIsSequence    (GstTocEntryType * type) { return GST_TOC_ENTRY_TYPE_IS_SEQUENCE(type); }
inline GstTocEntry *    copyTocEntry           (GstTocEntry * entry)    { return gst_toc_entry_copy(entry); }
inline GstTocEntry *    makeTocEntryWritable   (GstTocEntry * entry)    { return gst_toc_entry_make_writable(entry); }
inline GstTocEntry *    tocEntryRef            (GstTocEntry * entry)    { return gst_toc_entry_ref(entry); }
inline void             tocEntryUnref          (GstTocEntry * entry)    { gst_toc_entry_unref(entry); }
inline GstToc *         copyToc                (GstToc * toc)           { return gst_toc_copy(toc); }
inline GstToc *         makeTocWritable        (GstToc * toc)           { return gst_toc_make_writable(toc); }
inline GstToc *         tocRef                 (GstToc * toc)           { return gst_toc_ref(toc); }
inline void             tocUnref               (GstToc * toc)           { gst_toc_unref(toc); }

/* TagList utilities */

inline gboolean         tagListIsWritable     (GstTagList * tagList)   { return gst_tag_list_is_writable(tagList); }
inline GstTagList *     makeTagListWritable   (GstTagList * tagList)   { return gst_tag_list_make_writable(tagList); }

/* Object Utilities */

inline GObjectClass *  getGObjectClass         (void * p)                               { return (G_OBJECT_GET_CLASS(p)); }
inline gboolean        gstElementIsURIHandler  (GstElement * elem)                      { return (GST_IS_URI_HANDLER(elem)); }
inline gboolean        gstObjectFlagIsSet      (GstObject * obj, GstElementFlags flags) { return (GST_OBJECT_FLAG_IS_SET(obj, flags)); }

/* Element utilities */

inline GstTocSetter *  toTocSetter (GstElement * elem) { return GST_TOC_SETTER(elem); }
inline GstTagSetter *  toTagSetter (GstElement *elem)  { return GST_TAG_SETTER(elem); }

/*
	ParamSpec Utilities
*/

inline gboolean        isParamSpecTypeCaps   (GParamSpec * p) { return p->value_type == GST_TYPE_CAPS; }
inline gboolean        isParamSpecEnum       (GParamSpec * p) { return (G_IS_PARAM_SPEC_ENUM(p)); }
inline gboolean        isParamSpecFlags      (GParamSpec * p) { return (G_IS_PARAM_SPEC_FLAGS(p)); }
inline gboolean        isParamSpecObject     (GParamSpec * p) { return (G_IS_PARAM_SPEC_OBJECT(p)); }
inline gboolean        isParamSpecBoxed      (GParamSpec * p) { return (G_IS_PARAM_SPEC_BOXED(p)); }
inline gboolean        isParamSpecPointer    (GParamSpec * p) { return (G_IS_PARAM_SPEC_POINTER(p)); }
inline gboolean        isParamSpecFraction   (GParamSpec * p) { return (GST_IS_PARAM_SPEC_FRACTION(p)); }
inline gboolean        isParamSpecGstArray   (GParamSpec * p) { return p->value_type == GST_TYPE_ARRAY; }

inline GParamSpecUInt *    getParamUInt    (GParamSpec * param) { return (G_PARAM_SPEC_UINT(param)); }
inline GParamSpecInt *     getParamInt     (GParamSpec * param) { return (G_PARAM_SPEC_INT(param)); }
inline GParamSpecUInt64 *  getParamUInt64  (GParamSpec * param) { return (G_PARAM_SPEC_UINT64(param)); }
inline GParamSpecInt64 *   getParamInt64   (GParamSpec * param) { return (G_PARAM_SPEC_INT64(param)); }
inline GParamSpecFloat *   getParamFloat   (GParamSpec * param) { return (G_PARAM_SPEC_FLOAT(param)); }
inline GParamSpecDouble *  getParamDouble  (GParamSpec * param) { return (G_PARAM_SPEC_DOUBLE(param)); }

inline GEnumValue *    getEnumValues         (GParamSpec * p, guint * size)
{
	GEnumValue * values;
    values = G_ENUM_CLASS (g_type_class_ref (p->value_type))->values;
	guint i = 0;
	while (values[i].value_name) {
    	++i;
    }
	*size = i;
	return values;
}

inline GFlagsValue *   getParamSpecFlags     (GParamSpec * p, guint * size)
{
	GParamSpecFlags * pflags = G_PARAM_SPEC_FLAGS (p);
	GFlagsValue * vals = pflags->flags_class->values;
	guint i = 0;
	while (vals[i].value_name) {
    	++i;
    }
	*size = i;
	return vals;
}

/* Misc */

inline gpointer glistNext (GList * list)
{
	return g_list_next(list);
}

inline int sizeOfGCharArray (gchar ** arr)
{
	int i;
	for (i = 0 ; 1 ; i = i + 1) {
		if (arr[i] == NULL) { return i; };
	}
}

#endif
