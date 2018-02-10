#!/usr/bin/env python

print "hello, gushi!"

import wx

class MyApp(wx.App):
	def OnInit(self):
		wx.MessageBox("Hello wxPython", "wxApp")
return True