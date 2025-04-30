#include <iostream>
#include <list>
#include <string>
using namespace std;

class Notification
{
	protected:
		string message;
	public:
		Notification(string m) : message(m) {}
		virtual void envoyer() {
			cout << "Notification: " << message << endl;
		}
		virtual ~Notification() {}
};

class Email : public Notification 
{
	private:
		string destinataire;
	public:
		Email(string m, string dest) : Notification(m), destinataire(dest) {}
		void envoyer() override {
			cout << "Email a " << destinataire << ": " << message << endl;
		}
};

class SMS : public Notification 
{
	private:
		string numero;
	public:
		SMS(string m, string num) : Notification(m), numero(num) {}
		void envoyer() override 
		{
			cout << "SMS au " << numero << ": " << message << endl;
		}
};

int main()
{
    list<Notification*> notifications;
    notifications.push_back(new Notification("Message general"));
    notifications.push_back(new Email("Reunion demain", "user@example.com"));
    notifications.push_back(new SMS("N'oubliez pas le RDV", "0612345678"));
    for (auto notif : notifications)
        notif->envoyer();
    for (auto notif : notifications)
        delete notif;
    return 0;
}