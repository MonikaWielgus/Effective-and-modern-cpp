//Monika Wielgus
#include <iostream>
#include <regex>

int main(){

    const std::string s =  "<!DOCTYPE html> \n"
                             "<html lang=\"pl\">\n"
                             "<head>\n"
                             "  <title>Tomasz Kapela Homepage</title>\n"
                             "  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n"
                             "  <link rel=\"stylesheet\" type=\"text/css\" href=\"main.css\" />\n"
                             "  <style>\n"
                             "  table,\n"
                             "      td,\n"
                             "      th {\n"
                             "        padding: 5px;\n"
                             "        border: 2px solid black;\n"
                             "        border-radius: 5px;\n"
                             "      /*  background-color: #e5e5e5;*/\n"
                             "        text-align: center;\n"
                             "      }\n"
                             "</style>\n"
                             "</head>\n"
                             "<body>\n"
                             "<div id=\"center\">\n"
                             "\t\n"
                             "<div id=\"myHead\">\n"
                             "\t<div class=\"head1\"> \n"
                             "\t\t<a class=\"head1\" href=\"http://ww2.ii.uj.edu.pl/%7Ekapela/\">Tomasz Kapela Homepage </a> \n"
                             "    </div>\n"
                             "\t<div class=\"head2\"> \n"
                             "\t\t<a class=\"head2\" href=\"http://www.uj.edu.pl/\">Jagiellonian University</a> <br />\n"
                             "\t\t<a class=\"head2\" href=\"http://www.ii.uj.edu.pl/\">Institute of Computer Science and Computational Mathematics</a> \n"
                             "\t</div>\n"
                             "</div>\n"
                             "\n"
                             "<div id=\"myPhoto\"> <img src=\"http://ww2.ii.uj.edu.pl/%7Ekapela/img/kapela.jpg\" style=\"float: left;\" alt=\"Tomasz Kapela\" /> </div>\n"
                             "\n"
                             "<div id=\"menu\"> \n"
                             "\t<a href=\"index.php\"> HOME </a>\n"
                             "\t<a href=\"cv.php\"> CV </a> \n"
                             "\t<a href=\"papers/papers.html\"> PAPERS </a> \n"
                             "\t<a href=\"student/index.html\"> TEACHING</a> \n"
                             "\t<a href=\"nbody.php\"> N-BODY </a>  \n"
                             "\t<!-- a href=\"photo/index.html\">PHOTOS</a> -->\n"
                             "\t<a href=\"links.php\"> LINKS </a> \n"
                             "</div>\n"
                             "<div id=\"dataPanel\">\n"
                             "\n"
                             "\t<p>\n"
                             "\t<ul>\n"
                             "\t  <li><a href=\"https://baca.ii.uj.edu.pl\">BaCa</a></li>\n"
                             "\t  <li><a href=\"emcpp/\">Effective &amp; modern C++</a></li>\n"
                             "\t  <li><a href=\"https://www.solarsystemscope.com/\">\n"
                             "                 Solar System\n"
                             "          </a></li>\n"
                             "\t  <li><a href=\"http://www.usosweb.uj.edu.pl/\">USOS UJ </a></li>\n"
                             "          <li><a href=\"mailto:admin@helpdesk.eu\">Admin</a></li>\n"
                             "\t</ul>\n"
                             "\n"
                             "\t</p>\n"
                             "<table>\n"
                             "<tr><th>user</th><th>mail</th></tr>\n"
                             "<tr><td><a href=\"https://en.wikipedia.org/wiki/Donald_Duck\">Donald Duck</a></td><td>donald@duck.co</td></tr>\n"
                             "<tr><td>False email </td><td> to nie jest@email </td></tr>\n"
                             "<tr><td>XXXX</td><td>XX.xx-xx.XX@XXX.xx.pl </td></tr> \n"
                             "</table>\n"
                             "</div>\n"
                             "\n"
                             "</div>\n"
                             "\n"
                             "</body>\n"
                             "</html>";

    std::cout << "Links:" << std::endl;
    const std::regex reg("(https?://[www|en]?\\S*(.pl|.com)?\\/?)\">",std::regex::icase);
    auto match_begin1=std::sregex_token_iterator(s.begin(),s.end(),reg,1);
    auto match_end1=std::sregex_token_iterator();
    for(auto i=match_begin1; i!=match_end1; i++)
        std::cout << *i << std::endl;

    std::cout << "Emails:" << std::endl;
    const std::regex reg2("\\S*[>|:](\\S*@\\S*\\.(eu|pl|co|com))",std::regex::icase);
    auto match_begin2=std::sregex_token_iterator(s.begin(),s.end(),reg2,1);
    auto match_end2=std::sregex_token_iterator();
    for (auto i=match_begin2; i!=match_end2; i++) {
        std::cout << *i << std::endl;
    }
    return 0;
}
