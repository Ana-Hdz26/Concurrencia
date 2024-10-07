public class PingPong {
    private boolean isPingTurn = true;

    public synchronized void ping() {
        try {
            while (!isPingTurn) {
                wait();
            }
            System.out.print("P");
            isPingTurn = false;
            notify();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public synchronized void pong() {
        try {
            while (isPingTurn) {
                wait();
            }
            System.out.print("p");
            isPingTurn = true;
            notify();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) {
        PingPong pingPong = new PingPong();

        Thread pingThread = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                pingPong.ping();
            }
        });

        Thread pongThread = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                pingPong.pong();
            }
        });

        pingThread.start();
        pongThread.start();
    }
}
