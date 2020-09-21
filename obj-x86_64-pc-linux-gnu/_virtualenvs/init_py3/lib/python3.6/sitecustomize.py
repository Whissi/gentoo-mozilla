import site
site.addsitedir('/usr/lib/python3/dist-packages')
import os
os.environ['MOZBUILD_VIRTUALENV'] = '1'
# Importing mach_bootstrap has the side effect of
# installing an import hook
import mach_bootstrap
