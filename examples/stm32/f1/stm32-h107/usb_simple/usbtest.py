import usb.core

if __name__ == "__main__":
	dev = usb.core.find(idVendor=0xcafe, idProduct=0xcafe)
	if dev is None:
		raise ValueError('Device not found')

	dev.set_configuration()

	import gtk
	w = gtk.Window()
	w.connect("destroy", gtk.main_quit)
	toggle = gtk.ToggleButton("Toggle LED")
	def toggled(button):
		dev.ctrl_transfer(0x40, 0, button.get_active(), 0, 'Hello World!')
	toggle.connect("toggled", toggled)
	w.add(toggle)
	w.show_all()
	gtk.main()

