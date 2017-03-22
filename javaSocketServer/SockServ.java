import java.net.*; //подключение библиотек для работы с сетью
import java.io.*; //подключение библиотек для работы с потоками данных

public class SockServ
{
	public static void main(String[] argv)
	{
		System.out.println("Let's craft somthing");
		int port = 8888; //номер порта, который будет "прослушивать" сервер
		try
		{
			ServerSocket serv = new ServerSocket(port);//создаем серверный сокет
			System.out.println("Waiting for a client...");
			Socket client = serv.accept(); //assept ожидает подключения клиента; если клиент подключается, то accept возвращает сокет для взаимодействия с клиентом.
			System.out.println("Got a client!");
			//создаем потоки для обмена данными с клиентом.
			BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream())); //поток для чтения данных от клиента
			OutputStream out = client.getOutputStream(); //поток для отправки данных клиенту
			
			String line = null;//буфер для сохранения полученных данных
			while(true)
			{
				line = in.readLine(); //читаем строку данных отправленную клиентом
				if(line == null) break; //если не удалось считать строку то завершаем цикл
				System.out.println("Client sent: " + line);
				line += "\n";
				out.write(line.getBytes()); //отправляем данные клиенту
			}
		} catch(Exception e) { e.printStackTrace(); }		
	}
}
