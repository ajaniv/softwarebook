# Django settings for sb project.
import os

DEBUG = True
TEMPLATE_DEBUG = DEBUG

ADMINS = (
    # ('Your Name', 'your_email@domain.com'),
)

MANAGERS = ADMINS

DATABASES = {
     'default': {
        'ENGINE': 'django.db.backends.mysql',  
        'NAME': 'sb',                      
        'USER': 'ajaniv',                       
        'PASSWORD': 'aliza1979',                  
        'HOST': 'ajaniv-VL',                      # Set to empty string for localhost. Not used with sqlite3.
        'PORT': '3306',                      # Set to empty string for default. Not used with sqlite3.
    }
}

# Local time zone for this installation. Choices can be found here:
# http://en.wikipedia.org/wiki/List_of_tz_zones_by_name
# although not all choices may be available on all operating systems.
# On Unix systems, a value of None will cause Django to use the same
# timezone as the operating system.
# If running in a Windows environment this must be set to the same as your
# system time zone.
TIME_ZONE = 'America/Indiana/Indianapolis'

# Language code for this installation. All choices can be found here:
# http://www.i18nguy.com/unicode/language-identifiers.html
LANGUAGE_CODE = 'en-us'

SITE_ID = 2
ACCOUNT_ACTIVATION_DAYS=7



# If you set this to False, Django will make some optimizations so as not
# to load the internationalization machinery.
USE_I18N = True

# If you set this to False, Django will not format dates, numbers and
# calendars according to the current locale
USE_L10N = True

# Absolute filesystem path to the directory that will hold user-uploaded files.
# Example: "/home/media/media.lawrence.com/"
MEDIA_ROOT = 'D:/projects/ondalear/user_media/'

# URL that handles the media served from MEDIA_ROOT. Make sure to use a
# trailing slash if there is a path component (optional in other cases).
# Examples: "http://media.lawrence.com", "http://example.com/media/"
#MEDIA_URL = ''
MEDIA_URL = 'http://127.0.0.1:8000/user_media/'
#FILEBROWSER_MEDIA_URL = 'http://127.0.0.1:8000/user_media/'


PROJECT_ROOT = 'D:/projects/ondalear/'
STATIC_ROOT = PROJECT_ROOT + 'static/'
STATIC_URL='/static/'

STATICFILES_DIRS = (
   os.path.join(os.path.dirname(__file__), "core/static").replace('\\', '/'),

  
)



#FILEBROWSER_DIRECTORY='D:/projects/ondalear/user_media/uploads/'

# URL prefix for admin media -- CSS, JavaScript and images. Make sure to use a
# trailing slash.
# Examples: "http://foo.com/media/", "/media/".
#ADMIN_MEDIA_PREFIX = STATIC_URL
#ADMIN_MEDIA_PREFIX = STATIC_URL + "grappelli/"

# Make this unique, and don't share it with anybody.
SECRET_KEY = 'xt7ue9r7s0m*btu&4!j8$5a36qo6qeu5cn48l1mx*7f7_=52j#'

# List of callables that know how to import templates from various sources.
TEMPLATE_LOADERS = (
    'django.template.loaders.filesystem.Loader',
    'django.template.loaders.app_directories.Loader',
#     'django.template.loaders.eggs.Loader',
)

MIDDLEWARE_CLASSES = (
    'django.middleware.common.CommonMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.locale.LocaleMiddleware',
    'fileman.middleware.Anonymous_fileman_Setting'
)

ROOT_URLCONF = 'sb.urls'

TEMPLATE_DIRS = (
    # Put strings here, like "/home/html/django_templates" or "C:/www/django/templates".
    # Always use forward slashes, even on Windows.
    # Don't forget to use absolute paths, not relative paths.
    os.path.join(os.path.dirname(__file__), 'templates').replace('\\', '/'),
    os.path.join(os.path.dirname(__file__), 'fileman/templates').replace('\\', '/'),
)



TEMPLATE_CONTEXT_PROCESSORS = (
    'django.core.context_processors.debug',
    'django.core.context_processors.i18n',
    'django.core.context_processors.media',
    'django.core.context_processors.static',
    'django.contrib.auth.context_processors.auth',
    'django.contrib.messages.context_processors.messages',
    'fileman.context_processors.urls',
)


INSTALLED_APPS = (
    'django.contrib.sites',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.humanize',
    'form_utils',
    'sb.core',
    'sb.refdata',
    'sb.date',
    'sb.buscal',
    'sb.todo',
    'sb.blog',
    'sb.forum',
    'sb.event',
    'sb.art_exhibit',
    'sb.holiday_calc',
    'django.contrib.staticfiles',
   # 'grappelli',
   # 'filebrowser',
    # Uncomment the next line to enable the admin:
    'django.contrib.admin',
    #'fileman',
    # Uncomment the next line to enable admin documentation:
    'django.contrib.admindocs',
    'registration',
)

EMAIL_BACKEND = 'django.core.mail.backends.console.EmailBackend'