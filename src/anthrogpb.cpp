#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include "Logger.h"

namespace AnthroGPB {

    std::string grabToken() {
        std::ifstream tokenfile;
        tokenfile.open("token.txt");
        if (!tokenfile.is_open()) exit(-1);
        std::string BOT_TOKEN;
        tokenfile >> BOT_TOKEN;
        tokenfile.close();
        return BOT_TOKEN;
    }

    void initializeBot(dpp::cluster &bot) {

        bot.on_log(dpp::utility::cout_logger());

        bot.on_slashcommand([](const dpp::slashcommand_t& event) {
            if (event.command.get_command_name() == "ping") {
                event.reply("Pong!");
            }
            });

        bot.on_message_create([&bot](const dpp::message_create_t& event) {
            std::cout << event.msg.content;
            });

        bot.on_ready([&bot](const dpp::ready_t& event) {
            if (dpp::run_once<struct register_bot_commands>()) {
                bot.global_command_create(
                    dpp::slashcommand("ping", "Ping pong!", bot.me.id)
                );
            }
            });

        bot.start(dpp::st_wait);
    }

}

int main() {
    AnthroGDP::Logger::Log(AnthroGDP::Logger::LOG, "AnthroGPB is now loading...", false);
    std::string BOT_TOKEN = AnthroGPB::grabToken();
    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    AnthroGPB::initializeBot(bot);
    
}

