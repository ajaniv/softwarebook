import os
import logging
import logging.config


__dir__ = os.path.dirname(os.path.abspath(__file__))
log_file_path = os.path.join(__dir__, 'logging.conf')

logging.config.fileConfig(log_file_path)

# create logger
logger = logging.getLogger('businessCalendar')
logger.info('Logging initialized')