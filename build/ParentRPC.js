const startButton = document.getElementById('startButton');
const disconModal = document.getElementById('disconModal');
const accountPK = document.getElementById('account_pk_value');
const availableSOL = document.getElementById('sol_available_value');
const betInput = document.getElementById('bet_input');
const betButton = document.getElementById('bet_button');
const selectedValue = document.getElementById('selected_tile_value');
const errorModal = document.getElementById('errorModal');
const errorModalClose = document.getElementById('errorModalClose');
const processingModal = document.getElementById('processingModal');

var walletConnected = false;

const onStartClick = async (e) => {
  try {
    window.parent.postMessage(
      {
        name: 'INITIALIZE',
      },
      '*'
    );
    console.log('Connect from top');
    document.querySelector('#ui').style.zIndex = 0;
    document.querySelector('#ui').style.opacity = 0;
    document.getElementById('game').style.opacity = 1;
    document.getElementById('game').style.zIndex = 1;
    if (startGame) {
      startGame();
    }
  } catch (e) {
    console.log(e);
  }
};

startButton.onclick = onStartClick;
startButton.innerText = 'Start';

const onDisconnect = () => {
  console.log('Wallet disconnected please reconnect');
  disconModal.style.display = 'block';
};

betInput.onkeydown = (event) => {
  let num = Number(event.key);

  if (num >= 0 && num <= 9) {
    betInput.value = betInput.value + num;
  }

  if (event.key === 'Backspace') {
    var value = betInput.value;
    betInput.value = value.slice(0, -1);
  }
};

const onBetClicked = (e) => {
  //show error if the bet amount is more than the available sol and if a number is not selected

  const selected = Number(selectedValue.innerText) || 0;
  const amount = Number(betInput.value);

  if (
    selected === 0 ||
    amount === 0 ||
    amount > Number(availableSOL.innerText.slice(0, -4))
  ) {
    //show error
    errorModal.style.display = 'block';
    return;
  }

  //send a message to the parent with the bet amount and the number selected
  processingModal.style.display = 'flex';
  window.parent.postMessage(
    {
      name: 'BET',
      selected,
      amount,
    },
    '*'
  );
};

onBetModalClose = () => {
  errorModal.style.display = 'none';
};

betButton.onclick = onBetClicked;
errorModalClose.onclick = onBetModalClose;

window.addEventListener('message', (event) => {
  if (true) {
    console.log(event.data);

    switch (event.data.name) {
      case 'CONNECTION': {
        if (event.data.value === 'connected') {
          disconModal.style.display = 'none';
        } else if (event.data.value === 'disconnected') {
          onDisconnect();
        }

        break;
      }

      case 'PUBLIC_KEY': {
        const pk = event.data.value;
        var editted = pk.substring(0, 4);
        editted = editted + '...';
        editted = editted + pk.slice(pk.length - 5);

        accountPK.innerText = editted;
        break;
      }

      case 'SOL_AVAILABLE': {
        console.log(event.data);
        availableSOL.innerText = event.data.value + ' SOL';
        break;
      }

      default:
        break;
    }
  } else {
    return;
  }
});
