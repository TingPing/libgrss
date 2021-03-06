AC_PREREQ(2.62)

m4_define([grss_major_version], [0])
m4_define([grss_minor_version], [6])
m4_define([grss_micro_version], [0])
m4_define([grss_api_version], [0.6])
m4_define([grss_version],
          [grss_major_version.grss_minor_version.grss_micro_version])

AC_INIT([libgrss], [grss_version], [])

AC_CONFIG_HEADERS(config.h)

AM_INIT_AUTOMAKE([1.11 no-dist-gzip dist-xz tar-ustar])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_MACRO_DIR([m4])

GNOME_MAINTAINER_MODE_DEFINES

GRSS_MAJOR_VERSION=grss_major_version
GRSS_MINOR_VERSION=grss_minor_version
GRSS_MICRO_VERSION=grss_micro_version
LIBGRSS_API_VERSION=grss_api_version
LIBGRSS_VERSION=grss_version
AC_SUBST(GRSS_MAJOR_VERSION)
AC_SUBST(GRSS_MINOR_VERSION)
AC_SUBST(GRSS_MICRO_VERSION)
AC_SUBST(LIBGRSS_API_VERSION)
AC_SUBST(LIBGRSS_VERSION)

LT_PREREQ([2.2.6])
LT_INIT([dlopen disable-static])

IT_PROG_INTLTOOL([0.40.6])

AC_PROG_CC

GNOME_COMPILE_WARNINGS([maximum])

AC_ARG_ENABLE(deprecation_flags,
              [AC_HELP_STRING([--enable-deprecation-flags],
                              [use *_DISABLE_DEPRECATED flags @<:@default=no@:>@])],,
              [enable_deprecation_flags=no])

if test "x$enable_deprecation_flags" = "xyes"; then
   DISABLE_DEPRECATED_CFLAGS=$DISABLE_DEPRECATED
   AC_SUBST(DISABLE_DEPRECATED_CFLAGS)
fi

GETTEXT_PACKAGE=libgrss
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Package name])

AM_GLIB_GNU_GETTEXT

# AM_GLIB_GNU_GETTEXT above substs $DATADIRNAME
# this is the directory where the *.{mo,gmo} files are installed
grsslocaledir='${prefix}/${DATADIRNAME}/locale'
AC_SUBST(grsslocaledir)

AC_PATH_PROG(PKG_CONFIG, pkg-config)
AC_PATH_PROG([GLIB_GENMARSHAL], [glib-genmarshal])
AC_PATH_PROG([GLIB_MKENUMS], [glib-mkenums])
AC_CHECK_FUNCS([strptime localtime_r])

AC_CHECK_LIBM
AC_SUBST(LIBM)

PKG_CHECK_MODULES([LIBGRSS],[
	glib-2.0 >= 2.42.1
	libsoup-2.4 >= 2.48.0
	libxml-2.0 >= 2.9.2
])

##################################################
# Checks for gtk-doc and docbook-tools
##################################################
GTK_DOC_CHECK([1.9])

GOBJECT_INTROSPECTION_CHECK([1.30.0])

AC_OUTPUT([
	Makefile
	src/Makefile
	doc/Makefile
	doc/reference/Makefile
	doc/reference/version.xml
	po/Makefile.in
	libgrss.pc
])

dnl ---------------------------------------------------------------------------
dnl - Show summary
dnl ---------------------------------------------------------------------------

echo "
              libgrss $VERSION
              `echo libgrss $VERSION | sed "s/./=/g"`

        prefix:                       ${prefix}
        source code location:         ${srcdir}
        compiler:                     ${CC}
        cflags:                       ${CFLAGS}
        Maintainer mode:              ${USE_MAINTAINER_MODE}
        Use *_DISABLE_DEPRECATED:     ${enable_deprecation_flags}

        Build introspection support:  ${found_introspection}
        Build gtk-doc documentation:  ${enable_gtk_doc}

"
