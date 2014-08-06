#!/usr/bin/python

# Alternative approach.
import os
import MySQLdb
from apps.sb import settings

print 'drop remaining tables...'
for name, db in settings.DATABASES.iteritems():
    conn = MySQLdb.connect( db['HOST'], db['USER'], db['PASSWORD'], db['NAME'] )

    c = conn.cursor()
    c.execute('SET FOREIGN_KEY_CHECKS=0');
    c.execute('SHOW TABLES')
    for table in c.fetchall():
        print '\t', table[0]
        c.execute('DROP TABLE %s' % table[0])
    c.execute('SET FOREIGN_KEY_CHECKS=1');
    conn.close()