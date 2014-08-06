import re
from django import forms
from django.utils.safestring import mark_safe

class LinkFieldWidget(forms.Widget):
    '''
    A TextField widget with previewing link, generated from field's value with special url mask
    '''
    def __init__(self, text, url='', *args, **kwargs):
        self.url = url
        self.text = text
        
        super(LinkFieldWidget, self).__init__(*args, **kwargs)

    def render(self, name, value, attrs=None):
        output = []
        output.append('''<input type="text" name="%s" value="%s" />''' 
                      % (name, value or ''))
        if self.url and self.text:
            output.append('<span><a href="%s" id="%s-link"  style="display: %s;">%s</a></span>' 
                          % (self.url, name, value and 'inline' or 'none', self.text))

        return mark_safe(u' '.join(output))