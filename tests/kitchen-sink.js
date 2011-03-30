var gtk;
gtk = require('../build/default/gtk');
process.nextTick(function() {
  var button, entry, hbox, hbox2, hbox3, img, progress_hbox, progressbar, window;
  gtk.init();
  window = new gtk.Window;
  hbox = new gtk.Hbox;
  progress_hbox = new gtk.Hbox;
  window.add(hbox);
  hbox2 = new gtk.Hbox;
  hbox3 = new gtk.Hbox;
  entry = new gtk.Entry;
  progressbar = new gtk.ProgressBar;
  hbox.add(hbox2);
  hbox.add(hbox3);
  hbox.add(progress_hbox);
  progress_hbox.add(progressbar);
  progressbar.setFraction(0.45);
  entry.setText('A teeheehee!');
  entry.setVisibility(true);
  entry.on('changed', function() {
    return console.log('changed');
  });
  button = new gtk.Button;
  button.setLabel('Test Button');
  img = new gtk.Image;
  img.setFromFile('./data/ngtk.png');
  button.setImage(img);
  button.on('clicked', function() {
    var dialog;
    console.log('clicked');
    dialog = new gtk.MessageDialog(window, gtk.DIALOG_DESTROY_WITH_PARENT | gtk.DIALOG_MODAL, gtk.MESSAGE_INFO, gtk.BUTTONS_OK, 'Node.js + GTK <3');
    dialog.on('response', function(response) {
      console.log(response);
      return dialog.destroy();
    });
    return dialog.show();
  });
  hbox2.add(button);
  hbox3.add(entry);
  window.setTitle('Node');
  window.setResizable(true);
  window.setDefaultSize();
  window.on('destroy', function() {
    console.log(window.getOpacity());
    console.log(window.getPosition());
    console.log(window.getSize());
    console.log(window.getResizable(true));
    console.log(window.getTitle());
    return console.log('OMG');
  });
  return window.show();
});