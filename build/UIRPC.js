const selected = document.getElementById('selected_tile_value');

function UI_RPC(command, ...args) {
  console.log('Called: ', command, args[0]);

  switch (command) {
    case 'NUMBER_CHANGED':
      {
        if (selected) {
          selected.innerText = args[0];
        }
      }
      break;

    default:
      break;
  }
}
