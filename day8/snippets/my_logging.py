import logging

# This is the only way you should ever ever ever make a logger
logger = logging.getLogger(__name__)

# Will not print anything
logger.info('Here is a an info log')
logger.warning('Here is a warning log')

log_format = '%(asctime)-15s %(message)s'
logging.basicConfig(format=log_format, level=logging.INFO)

# Will print something
logger.info('Here is a an info log')
